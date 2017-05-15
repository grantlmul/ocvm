#include "model/host.h"
#include "io/frame.h"
#include "drivers/fs_utils.h"
#include "components/component.h"
#include "components/screen.h"
#include "components/gpu.h"
#include "components/eeprom.h"
#include "components/computer.h"
#include "components/filesystem.h"
#include "components/keyboard.h"
#include "components/internet.h"
#include "components/sandbox.h"

Host::Host(Framer* framer) :
    _framer(framer)
{
}

Host::~Host()
{
    close();
}

Component* Host::create(const string& type) const
{
    if (type == "screen")
    {
        return new Screen;
    }
    else if (type == "gpu")
    {
        return new Gpu;
    }
    else if (type == "eeprom")
    {
        return new Eeprom;
    }
    else if (type == "computer")
    {
        return new Computer;
    }
    else if (type == "filesystem")
    {
        return new Filesystem;
    }
    else if (type == "keyboard")
    {
        return new Keyboard;
    }
    else if (type == "internet")
    {
        return new Internet;
    }
    else if (type == "sandbox")
    {
        return new Sandbox;
    }

    return nullptr;
}

Framer* Host::getFramer() const
{
    return _framer;
}

void Host::close()
{
}
