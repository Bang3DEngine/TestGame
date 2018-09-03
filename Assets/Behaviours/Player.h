#include "Bang/Behaviour.h"

USING_NAMESPACE_BANG

class Player : public Behaviour
{
    COMPONENT(Player);

public:
    Player() = default;
    virtual ~Player() = default;

    void OnStart() override;
    void OnUpdate() override;

private:
    float jumpForce = 10.0f;
    RigidBody *rb = nullptr;

    float moveSpeed = 5.0f;
    float rotSpeed = 1.0f;
    float rotY = 0.0f;
};

BANG_BEHAVIOUR_CLASS(Player);
