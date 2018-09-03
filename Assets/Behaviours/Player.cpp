#include "Player.h"

void Player::OnStart()
{
    Behaviour::OnStart();

    rb = GetGameObject()->GetComponent<RigidBody>();
}

void Player::OnUpdate()
{
    Behaviour::OnUpdate();

    float inputSpeed = 0.0f;
    if (Input::GetKey(Key::W))
    {
        inputSpeed = 1.0f;
    }
    else if (Input::GetKey(Key::S))
    {
        inputSpeed = -1.0f;
    }

    if (Input::GetKey(Key::D))
    {
        rotY -= rotSpeed * Time::GetDeltaTime();
    }
    else if (Input::GetKey(Key::A))
    {
        rotY += rotSpeed * Time::GetDeltaTime();
    }

    GetGameObject()->GetTransform()->SetLocalRotation(
                Quaternion::AngleAxis(rotY, Vector3::Up));
    Vector3 vel = GetGameObject()->GetTransform()->GetForward() * moveSpeed * inputSpeed;

    float prevVelY = rb->GetLinearVelocity().y;
    vel.y = prevVelY;
    rb->SetLinearVelocity(vel);

    if (Input::GetKeyDown(Key::SPACE))
    {
        rb->AddForce(Vector3::Up * jumpForce, ForceMode::IMPULSE);
    }
}

BANG_BEHAVIOUR_CLASS_IMPL(Player);
