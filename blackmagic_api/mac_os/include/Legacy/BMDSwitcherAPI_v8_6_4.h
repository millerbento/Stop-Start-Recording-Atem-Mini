/* -LICENSE-START-
 ** Copyright (c) 2022 Blackmagic Design
 **
 ** Permission is hereby granted, free of charge, to any person or organization
 ** obtaining a copy of the software and accompanying documentation covered by
 ** this license (the "Software") to use, reproduce, display, distribute,
 ** execute, and transmit the Software, and to prepare derivative works of the
 ** Software, and to permit third-parties to whom the Software is furnished to
 ** do so, all subject to the following:
 **
 ** The copyright notices in the Software and this entire statement, including
 ** the above license grant, this restriction and the following disclaimer,
 ** must be included in all copies of the Software, in whole or in part, and
 ** all derivative works of the Software, unless such copies or derivative
 ** works are solely in the form of machine-executable object code generated by
 ** a source language processor.
 **
 ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 ** FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 ** SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 ** FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 ** ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 ** DEALINGS IN THE SOFTWARE.
 ** -LICENSE-END-
 */

#ifndef BMD_BMDSWITCHERAPI_V8_6_4_H
#define BMD_BMDSWITCHERAPI_V8_6_4_H


#ifndef BMD_CONST
    #if defined(_MSC_VER)
        #define BMD_CONST __declspec(selectany) static const
    #else
        #define BMD_CONST static const
    #endif
#endif

#include "BMDSwitcherAPI.h"

BMD_CONST REFIID IID_IBMDSwitcherTalkback_v8_6_4                         = /* 5FB45599-DD69-49C5-AB0B-D7D593829E63 */ { 0x5F,0xB4,0x55,0x99,0xDD,0x69,0x49,0xC5,0xAB,0x0B,0xD7,0xD5,0x93,0x82,0x9E,0x63 };
BMD_CONST REFIID IID_IBMDSwitcherTalkbackIterator_v8_6_4                 = /* 17AC2EFF-C51A-41AB-A4CB-3C3AF2157FFE */ { 0x17,0xAC,0x2E,0xFF,0xC5,0x1A,0x41,0xAB,0xA4,0xCB,0x3C,0x3A,0xF2,0x15,0x7F,0xFE };


#if defined(__cplusplus)

// Forward Declarations

class IBMDSwitcherTalkback_v8_6_4;
class IBMDSwitcherTalkbackIterator_v8_6_4;


/* Interface IBMDSwitcherTalkback_v8_6_4 - Talkback Object */

class BMD_PUBLIC IBMDSwitcherTalkback_v8_6_4 : public IUnknown
{
public:
    virtual HRESULT GetId (/* out */ BMDSwitcherTalkbackId* talkbackId) = 0;
    virtual HRESULT GetMuteSDI (/* out */ bool* muteSDI) = 0;
    virtual HRESULT SetMuteSDI (/* in */ bool muteSDI) = 0;
    virtual HRESULT InputCanMuteSDI (/* in */ BMDSwitcherAudioInputId audioInputId, /* out */ bool* canMuteSDI) = 0;
    virtual HRESULT CurrentInputSupportsMuteSDI (/* in */ BMDSwitcherAudioInputId audioInputId, /* out */ bool* supportsMuteSDI) = 0;
    virtual HRESULT GetInputMuteSDI (/* in */ BMDSwitcherAudioInputId audioInputId, /* out */ bool* muteSDI) = 0;
    virtual HRESULT SetInputMuteSDI (/* in */ BMDSwitcherAudioInputId audioInputId, /* in */ bool muteSDI) = 0;
    virtual HRESULT AddCallback (/* in */ IBMDSwitcherTalkbackCallback* callback) = 0;
    virtual HRESULT RemoveCallback (/* in */ IBMDSwitcherTalkbackCallback* callback) = 0;

protected:
    virtual ~IBMDSwitcherTalkback_v8_6_4 () {} // call Release method to drop reference count
};

/* Interface IBMDSwitcherTalkbackIterator_v8_6_4 - Talkback Iterator v8.6.4 */

class BMD_PUBLIC IBMDSwitcherTalkbackIterator_v8_6_4 : public IUnknown
{
public:
	virtual HRESULT Next (/* out */ IBMDSwitcherTalkback_v8_6_4** talkback) = 0;
	virtual HRESULT GetById (/* in */ BMDSwitcherTalkbackId talkbackId, /* out */ IBMDSwitcherTalkback_v8_6_4** talkback) = 0;

protected:
	virtual ~IBMDSwitcherTalkbackIterator_v8_6_4 () {} // call Release method to drop reference count
};

#endif      // defined(__cplusplus)
#endif /* defined(BMD_BMDSWITCHERAPI_V8_6_4_H) */