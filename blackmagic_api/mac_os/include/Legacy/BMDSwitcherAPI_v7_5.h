/* -LICENSE-START-
** Copyright (c) 2018 Blackmagic Design
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

#ifndef BMD_BMDSWITCHERAPI_V7_5_H
#define BMD_BMDSWITCHERAPI_V7_5_H

#include "BMDSwitcherAPI.h"

// Interface ID Declarations
BMD_CONST REFIID IID_IBMDSwitcherMixEffectBlock_v7_5			= /* 11974D55-45E0-49D8-AE06-EEF4D5F81DF6 */ {0x11,0x97,0x4D,0x55,0x45,0xE0,0x49,0xD8,0xAE,0x06,0xEE,0xF4,0xD5,0xF8,0x1D,0xF6};
BMD_CONST REFIID IID_IBMDSwitcherMixEffectBlockIterator_v7_5	= /* 930BDE3B-4A78-43D0-8FD3-6E82ABA0E117 */ {0x93,0x0B,0xDE,0x3B,0x4A,0x78,0x43,0xD0,0x8F,0xD3,0x6E,0x82,0xAB,0xA0,0xE1,0x17};
BMD_CONST REFIID IID_IBMDSwitcherMixEffectBlockCallback_v7_5 	= /* 96010829-2029-4DA3-A34B-70368605ABAA */ {0x96,0x01,0x08,0x29,0x20,0x29,0x4D,0xA3,0xA3,0x4B,0x70,0x36,0x86,0x05,0xAB,0xAA};


#if defined(__cplusplus)

// Forward Declarations
class IBMDSwitcherMixEffectBlockCallback_v7_5;
class IBMDSwitcherMixEffectBlock_v7_5;
class IBMDSwitcherMixEffectBlockIterator_v7_5;

/* Enum BMDSwitcherMixEffectBlockPropertyId_v7_5 - IBMDSwitcherMixEffectBlock_v7_5 Property ID */

typedef uint32_t BMDSwitcherMixEffectBlockPropertyId_v7_5;
enum _BMDSwitcherMixEffectBlockPropertyId_v7_5 {
	bmdSwitcherMixEffectBlockPropertyIdProgramInput_v7_5                = 'pgip',	// Int type (BMDSwitcherInputId), Get/Set
	bmdSwitcherMixEffectBlockPropertyIdPreviewInput_v7_5                = 'pvip',	// Int type (BMDSwitcherInputId), Get/Set
	bmdSwitcherMixEffectBlockPropertyIdTransitionPosition_v7_5          = 'tsps',	// Float type, Get/Set
	bmdSwitcherMixEffectBlockPropertyIdTransitionFramesRemaining_v7_5   = 'tfrm',	// Int type, Get only
	bmdSwitcherMixEffectBlockPropertyIdInTransition_v7_5                = 'iits',	// Flag type, Get only
	bmdSwitcherMixEffectBlockPropertyIdFadeToBlackFramesRemaining_v7_5  = 'ffrm',	// Int type, Get only
	bmdSwitcherMixEffectBlockPropertyIdInFadeToBlack_v7_5               = 'iifb',	// Flag type, Get only
	bmdSwitcherMixEffectBlockPropertyIdPreviewLive_v7_5                 = 'pvlv',	// Flag type, Get only
	bmdSwitcherMixEffectBlockPropertyIdPreviewTransition_v7_5           = 'pvts',	// Flag type, Get/Set
	bmdSwitcherMixEffectBlockPropertyIdInputAvailabilityMask_v7_5       = 'iavm',	// Int type (BMDSwitcherInputAvailability), Get only
	bmdSwitcherMixEffectBlockPropertyIdFadeToBlackRate_v7_5             = 'ftbr',	// Int type, Get/Set
	bmdSwitcherMixEffectBlockPropertyIdFadeToBlackFullyBlack_v7_5       = 'ftbb',	// Flag type, Get/Set
	bmdSwitcherMixEffectBlockPropertyIdFadeToBlackInTransition_v7_5     = 'ftbt'	// Flag type, Get only
};

/* Interface IBMDSwitcherMixEffectBlockCallback_v7_5 - Mix Effect Block v7_5 Notification Callback */

class IBMDSwitcherMixEffectBlockCallback_v7_5 : public IUnknown
{
public:
	virtual HRESULT PropertyChanged (/* in */ BMDSwitcherMixEffectBlockPropertyId_v7_5 propertyId) = 0;

protected:
	virtual ~IBMDSwitcherMixEffectBlockCallback_v7_5 () {} // call Release method to drop reference count
};

/* Interface IBMDSwitcherMixEffectBlock_v7_5 - Mix Effect Block v7_5 */

class IBMDSwitcherMixEffectBlock_v7_5 : public IUnknown
{
public:
    virtual HRESULT CreateIterator (/* in */ REFIID iid, /* out */ LPVOID* ppv) = 0;
	virtual HRESULT AddCallback (/* in */ IBMDSwitcherMixEffectBlockCallback_v7_5* callback) = 0;
	virtual HRESULT RemoveCallback (/* in */ IBMDSwitcherMixEffectBlockCallback_v7_5* callback) = 0;
	virtual HRESULT SetFlag (/* in */ BMDSwitcherMixEffectBlockPropertyId_v7_5 propertyId, /* in */ bool value) = 0;
	virtual HRESULT GetFlag (/* in */ BMDSwitcherMixEffectBlockPropertyId_v7_5 propertyId, /* out */ bool* value) = 0;
	virtual HRESULT SetInt (/* in */ BMDSwitcherMixEffectBlockPropertyId_v7_5 propertyId, /* in */ int64_t value) = 0;
	virtual HRESULT GetInt (/* in */ BMDSwitcherMixEffectBlockPropertyId_v7_5 propertyId, /* out */ int64_t* value) = 0;
	virtual HRESULT SetFloat (/* in */ BMDSwitcherMixEffectBlockPropertyId_v7_5 propertyId, /* in */ double value) = 0;
	virtual HRESULT GetFloat (/* in */ BMDSwitcherMixEffectBlockPropertyId_v7_5 propertyId, /* out */ double* value) = 0;
	virtual HRESULT SetString (/* in */ BMDSwitcherMixEffectBlockPropertyId_v7_5 propertyId, /* in */ CFStringRef value) = 0;
	virtual HRESULT GetString (/* in */ BMDSwitcherMixEffectBlockPropertyId_v7_5 propertyId, /* out */ CFStringRef* value) = 0;
    virtual HRESULT PerformAutoTransition (void) = 0;
    virtual HRESULT PerformCut (void) = 0;
    virtual HRESULT PerformFadeToBlack (void) = 0;

protected:
	virtual ~IBMDSwitcherMixEffectBlock_v7_5 () {} // call Release method to drop reference count
};

/* Interface IBMDSwitcherMixEffectBlockIterator_v7_5 - Mix Effect Block v7_5 Iterator */

class IBMDSwitcherMixEffectBlockIterator_v7_5 : public IUnknown
{
public:
	virtual HRESULT Next (/* out */ IBMDSwitcherMixEffectBlock_v7_5** mixEffectBlock) = 0;

protected:
	virtual ~IBMDSwitcherMixEffectBlockIterator_v7_5 () {} // call Release method to drop reference count
};

#endif	/* defined(__cplusplus) */
#endif	/* BMD_BMDSWITCHERAPI_V7_5_H */
