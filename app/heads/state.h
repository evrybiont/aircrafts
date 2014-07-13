#ifndef STATE_H
#define STATE_H

class State {
  protected:
    bool is_active;
    enum scope { INTRO_AREA = 1, MENU_AREA, LEVELS_AREA };
  public:
    State();
    virtual void init() = 0;
    virtual int nextArea() = 0;
};

#endif
