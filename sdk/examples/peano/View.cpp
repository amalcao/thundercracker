#include "View.h"
#include "TotalsCube.h"

namespace TotalsGame
{

View::View(TotalsCube *_cube)
{
    mCube = NULL;
    mLockCount = 0;
    SetCube(_cube);
    if(mCube)
        mCube->SetView(this);
}

void View::PaintViews(TotalsCube *cubes, int numCubes)
{
    for(int i = 0; i < numCubes; i++)
    {
        View *v = cubes[i].GetView();
        if(v) v->Paint();
    }
}

void View::SetCube(TotalsCube *c)
{
    if (mCube != c)
    {
        if (mCube != NULL)
        {            
            //if (willDetachFromCube != null) { willDetachFromCube(this); }
            mCube->SetView(NULL);
        }
        mCube = c;
        if (mCube != NULL)
        {
            View *view = mCube->GetView();
            if (view != NULL && view != this)
            {
                view->SetCube(NULL);
            }
            c->SetView(this);
            //if (didAttachToCube != null) { didAttachToCube(this); }
            Paint();
        }
    }

}

TotalsCube *View::GetCube()
{
    return mCube;
}

}
