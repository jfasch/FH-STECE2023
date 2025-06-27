#include "push-button-gpio.h"


PushButtonGpio::PushButtonGpio(State state, unsigned int line_offset, const std::string& chipname)
: _request(::gpiod::chip(chipname)
                               .prepare_request()
                               .add_line_settings(
                                       line_offset,
                                       ::gpiod::line_settings().set_direction(
                                               ::gpiod::line::direction::INPUT))
                               .do_request())

{
    line_offset_ = line_offset;
}
PushButton::State PushButtonGpio::get_state()
{
    auto value = _request.get_value(line_offset_);
    if (value == gpiod::line::value::ACTIVE)
        return PushButton::State::PRESSED;
    else
        return PushButton::State::RELEASED;
}

