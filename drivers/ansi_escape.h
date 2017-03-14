#pragma once

#include "io/frame.h"

#include <vector>
#include <map>

using std::map;

struct AnsiFrameState
{
};

class AnsiEscapeTerm : public Framer
{
public:
    ~AnsiEscapeTerm();
    bool update() override;
    void onResolution(Frame* pWhichFrame) override;
    tuple<int, int> maxResolution() const override;
protected:
    bool onOpen() override;
    void onClose() override;
    void onWrite(Frame* pf, int x, int y, const Cell& cell) override;
    bool onAdd(Frame* pf) override;
private:
    map<Frame*, AnsiFrameState> _states;
};