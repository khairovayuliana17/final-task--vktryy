
#include "vampire.h"

class OriginalVampire : public Vampire {
  private:
    int sireLine;

  public:
    OriginalVampire(const std::string& name, int age);

    int getSireLine() const;

    void compel();
    void createVampire();
};
