/*
 * Thundercracker Firmware -- Confidential, not for redistribution.
 * Copyright <c> 2012 Sifteo, Inc. All rights reserved.
 */

/*
 * High-level radio interface. This is the glue between our
 * cross-platform code and the low-level nRF radio driver.
 */

#include "radio.h"
#include "nrf24l01.h"

void Radio::init()
{
    NRF24L01::instance.init();
}

void Radio::begin()
{
    NRF24L01::instance.beginTransmitting();
}

void Radio::halt()
{
    /*
     * Wait for any interrupt
     *
     * Disabled during debug builds. WFI loops make JTAG debugging
     * very annoying, since the JTAG clock is also turned off while
     * we're waiting.
     */

#ifndef DEBUG
    __asm__ __volatile__ ("wfi");
#endif
}

void Radio::setTxPower(TxPower pwr)
{
    NRF24L01::instance.setTxPower(pwr);
}

Radio::TxPower Radio::txPower()
{
    return NRF24L01::instance.txPower();
}
