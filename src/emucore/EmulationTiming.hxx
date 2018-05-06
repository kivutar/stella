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
// Copyright (c) 1995-2018 by Bradford W. Mott, Stephen Anthony
// and the Stella Team
//
// See the file "License.txt" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//============================================================================

#ifndef EMULATION_TIMING_HXX
#define EMULATION_TIMING_HXX

#include "bspf.hxx"
#include "FrameLayout.hxx"

class EmulationTiming {
  public:

    EmulationTiming(FrameLayout frameLayout = FrameLayout::ntsc);

    void updateFrameLayout(FrameLayout frameLayout);

    void updatePlaybackRate(uInt32 playbackRate);

    void updatePlaybackPeriod(uInt32 period);

    uInt32 maxCyclesPerTimeslice() const;

    uInt32 minCyclesPerTimeslice() const;

    uInt32 linesPerFrame() const;

    uInt32 cyclesPerFrame() const;

    uInt32 framesPerSecond() const;

    uInt32 cyclesPerSecond() const;

    uInt32 audioFragmentSize() const;

    uInt32 audioSampleRate() const;

    uInt32 audioQueueCapacity() const;

    uInt32 prebufferFragmentCount() const;

  private:

    FrameLayout myFrameLayout;

    uInt32 myPlaybackRate;

    uInt32 myPlaybackPeriod;

};

#endif // EMULATION_TIMING_HXX
