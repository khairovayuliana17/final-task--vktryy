#include "vampire.h"

class Doppelganger : public Vampire {
  private:
    std::string originalName;
    int bloodMagicReserve;

  public:
    Doppelganger(const std::string& name, int age, const std::string& originalName);

    std::string getOriginalName() const;
    int getBloodMagicReserve() const;

    void confuseEnemy();
    void decreaseBloodMagicReserve();
};
