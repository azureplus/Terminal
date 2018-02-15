/*++
Copyright (c) Microsoft Corporation

Module Name:
- InteractDispatch.hpp

Abstract:
- Base class for Input State Machine callbacks. When actions occur, they will
    be dispatched to the methods on this interface which must be implemented by
    a child class and passed into the state machine on creation.

Author(s):
- Mike Griese (migrie) 11 Oct 2017
--*/
#pragma once

#include "DispatchCommon.hpp"
#include "../../types/inc/IInputEvent.hpp"

namespace Microsoft
{
    namespace Console
    {
        namespace VirtualTerminal
        {
            class IInteractDispatch;
        }
    }
}

class Microsoft::Console::VirtualTerminal::IInteractDispatch
{
public:
    virtual ~IInteractDispatch() = default;

    virtual bool WriteInput(_In_ std::deque<std::unique_ptr<IInputEvent>>& inputEvents) = 0;

    virtual bool WriteCtrlC() = 0;

    virtual bool WriteString(_In_reads_(cch) const wchar_t* const pws, _In_ const size_t cch) = 0;

    virtual bool WindowManipulation(_In_ const DispatchCommon::WindowManipulationType uiFunction,
                                    _In_reads_(cParams) const unsigned short* const rgusParams,
                                    _In_ size_t const cParams) = 0;

    virtual bool MoveCursor(_In_ const unsigned int row,
                            _In_ const unsigned int col) = 0;

};
