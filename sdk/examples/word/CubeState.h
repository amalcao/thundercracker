#ifndef CUBESTATE_H
#define CUBESTATE_H

#include <sifteo.h>
#include "State.h"
#include "TileTransparencyLookup.h"

enum CubeStateIndex
{
    CubeStateIndex_Title,
    CubeStateIndex_TitleExit,
    CubeStateIndex_NotWordScored,
    CubeStateIndex_NewWordScored,
    CubeStateIndex_OldWordScored,
    CubeStateIndex_StartOfRoundScored,
    CubeStateIndex_EndOfRoundScored,
    CubeStateIndex_ShuffleScored,

    CubeStateIndex_NumStates
};

enum EyeState
{
    EyeState_Closed = -2,
    EyeState_Center = -1,
    EyeState_N = 0,
    EyeState_NW,
    EyeState_W,
    EyeState_SW,
    EyeState_S,
    EyeState_SE,
    EyeState_E,
    EyeState_NE,

    NumEyeStates
};

class CubeStateMachine;
const float TEETH_ANIM_LENGTH = 1.7f;

class CubeState : public State
{
public:
    CubeState() :
        mStateMachine(0), mEyeState(EyeState_Center), mEyeDirChangeDelay(0.f),
        mEyeBlinkDelay(0.f), mAsleep(false) { }

    void setStateMachine(CubeStateMachine& csm);
    CubeStateMachine& getStateMachine();

protected:
    virtual unsigned update(float dt, float stateTime);

private:
    CubeStateMachine* mStateMachine;
    EyeState mEyeState;
    float mEyeDirChangeDelay;
    float mEyeBlinkDelay;
    bool mAsleep;
};

#endif // CUBESTATE_H
