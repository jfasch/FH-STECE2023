#pragma once
#include <string>
#include "push-button.h"
#include <gpiod.hpp>

class PushButtonGpio : public PushButton
{
public:
    PushButtonGpio(State state, unsigned int line_offset, const std::string& chipname = "/dev/gpiochip0");
    PushButton::State get_state() override;
    gpiod::line_request _request;

private:
 unsigned int line_offset_; 
  std::string chipname_;
};
