
#pragma once
#include <memory>

struct ICommand {
    virtual ~ICommand() = default;
    virtual void execute() = 0;
};

using CommandPtr = std::unique_ptr<ICommand>;
