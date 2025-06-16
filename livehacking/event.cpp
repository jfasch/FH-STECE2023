#include <iostream>


class Event
{
public:
    Event& set_do_open() { _do_open = true; return *this; }
    Event& set_do_close() { _do_close = true; return *this; }
    Event& set_open_position_reached() { _open_position_reached = true; return *this; }
    Event& set_closed_position_reached() { _closed_position_reached = true; return *this; }
    Event& set_open_timer_expired() { _open_timer_expired = true; return *this; }

    bool do_open() const { return _do_open; }
    bool do_close() const { return _do_close; }
    bool open_position_reached() const { return _open_position_reached; }
    bool closed_position_reached() const { return _closed_position_reached; }
    bool open_timer_expired() const { return _open_timer_expired; }

private:
    bool _do_open{false};
    bool _do_close{false};
    bool _open_position_reached{false};
    bool _closed_position_reached{false};
    bool _open_timer_expired{false};
};

int main()
{
    auto event = Event().set_do_open().set_open_timer_expired();

    std::cout << "do_open: " << event.do_open() << std::endl;
    std::cout << "do_close: " << event.do_close() << std::endl;
    std::cout << "open_position_reached: " << event.open_position_reached() << std::endl;
    std::cout << "closed_position_reached: " << event.closed_position_reached() << std::endl;
    std::cout << "open_timer_expired: " << event.open_timer_expired() << std::endl;

    return 0;
}
