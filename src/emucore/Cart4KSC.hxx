//============================================================================
//
//   SSSS    tt          lll  lll
//  SS  SS   tt           ll   ll
//  SS     tttttt  eeee   ll   ll   aaaa
//   SSSS    tt   ee  ee  ll   ll      aa
//      SS   tt   eeeeee  ll   ll   aaaaa  --  "An Atari 2600 VCS Emulator"
//  SS  SS   tt   ee      ll   ll  aa  aa
//   SSSS     ttt  eeeee llll llll  aaaaa
//
// Copyright (c) 1995-2020 by Bradford W. Mott, Stephen Anthony
// and the Stella Team
//
// See the file "License.txt" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//============================================================================

#ifndef CARTRIDGE4KSC_HXX
#define CARTRIDGE4KSC_HXX

class System;

#include "bspf.hxx"
#include "Cart4K.hxx"
#ifdef DEBUGGER_SUPPORT
  #include "Cart4KSCWidget.hxx"
#endif

/**
  Cartridge class used for 4K games with 128 bytes of RAM.
  RAM read port is $1080 - $10FF, write port is $1000 - $107F.

  @author  Stephen Anthony, Thomas Jentzsch
*/

class Cartridge4KSC : public Cartridge4K
{
  friend class Cartridge4KSCWidget;

  public:
    /**
      Create a new cartridge using the specified image

      @param image     Pointer to the ROM image
      @param size      The size of the ROM image
      @param md5       The md5sum of the ROM image
      @param settings  A reference to the various settings (read-only)
    */
    Cartridge4KSC(const ByteBuffer& image, size_t size, const string& md5,
                  const Settings& settings);
    virtual ~Cartridge4KSC() = default;

  public:
    /**
      Get a descriptor for the device name (used in error checking).

      @return The name of the object
    */
    string name() const override { return "Cartridge4KSC"; }

  #ifdef DEBUGGER_SUPPORT
    /**
      Get debugger widget responsible for accessing the inner workings
      of the cart.
    */
    CartDebugWidget* debugWidget(GuiObject* boss, const GUI::Font& lfont,
        const GUI::Font& nfont, int x, int y, int w, int h) override
    {
      return new Cartridge4KSCWidget(boss, lfont, nfont, x, y, w, h, *this);
    }
  #endif

  private:
    // RAM size
    static constexpr size_t RAM_SIZE = 0x80;

  private:
    // Following constructors and assignment operators not supported
    Cartridge4KSC() = delete;
    Cartridge4KSC(const Cartridge4KSC&) = delete;
    Cartridge4KSC(Cartridge4KSC&&) = delete;
    Cartridge4KSC& operator=(const Cartridge4KSC&) = delete;
    Cartridge4KSC& operator=(Cartridge4KSC&&) = delete;
};

#endif
