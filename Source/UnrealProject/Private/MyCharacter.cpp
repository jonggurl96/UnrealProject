// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 컴포넌트 생성은 생성자 내부에서만 가능
	BackSpring = CreateDefaultSubobject<USpringArmComponent>(TEXT("Back Spring Arm"));
	BackCam = CreateDefaultSubobject<UCameraComponent>(TEXT("Back Camera"));

	// Root Component에 SpringArmComponent를 장착하고 그 끝에 소켓에 CameraComponent 장착
	BackSpring->SetupAttachment(RootComponent);
	BackCam->SetupAttachment(CastChecked<USceneComponent, USpringArmComponent>(BackSpring), USpringArmComponent::SocketName);

	// RootComponent와 SpringArm 사이의 스프링 거리
	BackSpring->TargetArmLength = 300.0f;

	// SpringArmComponent의 높이 조절
	BackSpring->SetRelativeLocation(FVector(0.0f, 0.0f, 20.0f + BaseEyeHeight));

	// CapsuleComponent의 높이 설정
	GetCapsuleComponent()->SetCapsuleHalfHeight(97.0f);

	// 카메라 회전 시 캐릭터도 함께 회전하지 않도록 설정
	bUseControllerRotationYaw = false;

	// 캐릭터가 움직이는 방향으로 회전 후 이동
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// SpringArmComponent가 바라보는 방향으로 폰 회전
	BackSpring->bUsePawnControlRotation = true;

	// 기본 플레이어인 Player0이 컨트롤할 수 있도록 설정
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("MyCharacter beginPlay."));
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);

	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("StartJump", IE_Pressed, this, &AMyCharacter::StartJump);

	PlayerInputComponent->BindAction("StopJump", IE_Released, this, &AMyCharacter::StopJump);

}

FRotator AMyCharacter::MakeRotator() const
{
	return FRotator(0.0f, GetControlRotation().Yaw, 0.0f);
}

void AMyCharacter::MoveForward(float Value)
{
	FVector ForwardDirection = MakeRotator().Vector();
	AddMovementInput(ForwardDirection, Value);
}

void AMyCharacter::MoveRight(float Value)
{
	FVector WorldDirection = FRotationMatrix(MakeRotator()).GetScaledAxis(EAxis::Y);
	AddMovementInput(WorldDirection, Value);
}

void AMyCharacter::StartJump()
{
	bPressedJump = true;
}

void AMyCharacter::StopJump()
{
	bPressedJump = false;
}

