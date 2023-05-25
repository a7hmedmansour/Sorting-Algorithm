/*
 * Timer0.c
 *
 * Created: 16-May-23 8:43:10 PM
 *  Author: A7MED
 */ 

#include "Timer0.h"

#define F_CPU (16000000UL)

static void(*g_callbackPTR)(uint8)=NULL_PTR;
static uint8 g_callbackValue = 0;
static uint8 *g_dataPTR = NULL_PTR;
static uint16_t g_delay_ms = 0;
static bool g_delay_expired = FALSE;

void Timer0_init()
{
    TCNT0 = 0;
    SET_BIT(TIMSK, TOIE0);
    TCCR0 = (1 << FOC0) | (1 << CS02) | (1 << CS00);
    SET_BIT(SREG, I_BIT);

    g_callbackPTR = NULL_PTR;
    g_callbackValue = 0;
    g_dataPTR = NULL_PTR;
    g_delay_ms = 0;
    g_delay_expired = FALSE;
}

void Timer0_setcallback(void(*ptr)(uint8), uint8 value)
{
    g_callbackPTR = ptr;
    g_callbackValue = value;
}

void Timer0_setdata(uint8 *data)
{
    g_dataPTR = data;
}

void Timer0_setDelay(uint16_t delay_ms)
{
    g_delay_ms = delay_ms;
}

ISR(TIMER0_OVF_vect)
{
    static uint16_t ovf_count = 0;
    ovf_count++;

    if (g_callbackPTR != NULL_PTR)
    {
        (*g_callbackPTR)(g_callbackValue);
    }

    if (g_dataPTR != NULL_PTR)
    {
        (*g_dataPTR)++;
    }

    if (g_delay_ms > 0)
    {
        uint16_t ovf_required = (g_delay_ms * F_CPU) / (1024UL * 256UL * 1000UL);
        if (ovf_count >= ovf_required)
        {
            ovf_count = 0;
            g_delay_expired = TRUE;
        }
    }
}