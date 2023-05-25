# UnrealProject

## 일반적인 Unreal Project의 진행 순서
1. AActor 클래스를 상속받는 C++ 클래스를 작성 후 빌드
   [사진 넣을거임]()
2. 빌드한 소스코드로부터 블루프린트 생성 후 컴파일
   [사진 넣을거임]()
3. 컴파일 된 블루프린트를 뷰포트에 배치하여 맵 완성
   [사진 넣을거임]()
4. 기본 맵 설정 및 맵을 연결해 월드 생성 후 배포
   [사진 넣을거임](exe파일 하나 보여주면 되겠지)

# Editor Tools
<img src="https://img.shields.io/badge/Rider-purple?style=flat&logo=Rider&logoColor=#000000"/>
<br>
<img src="https://img.shields.io/badge/Unreal Editor 5.1.1-black?style=flat&logo=unrealengine&logoColor=#0E1128"/>

## Unreal Editor 화면
![](github_resources/Editor.png)
- ViewPort
  - 현재 작업중인 맵이 보여지는 화면
  - 액터를 배치하고 이동, 회전, 스케일링 하는 등의 작업이 가능함
- Docked Layout
  - Content Browser(Drawer), OutputLog 등의 창을 고정 가능한 레이아웃
- Outliner
  - 뷰포트에 배치된 액터들을 확인할 수 있음
  - 폴더를 생성해 묶어서 관리할 수 있음
- Details
  - 뷰포트의 액터를 선택해 위치, 회전 등의 작업과 컴포넌트 추가 등을 지원해주는 창

## Editor Tool 비교
### Visual Studio
#### Vsual Studio Workloads
- .NET desktop development
- Desktop development with C++
- Universal Windows Platform development
- Game development with C++
  - C++ profiling tools
  - C++ AddressSanitizer
  - Windows 10 SDK
  - IntelliCode
> Unreal 문법 작성 시 들여쓰기 문제로 플러그인을 추가로 설치해줘야 하고 프로그램 자체가 무거움 

### Visual Studio Code
#### Extensions
- C/C++ Extensions Pack
- C# Extensions
> 필요한 익스텐션이 얼마 없는게 당연한 게 UE IntelliSense Extension이 5점대는 지원해주지 않음

### Rider
#### Plugins
- RiderLink(Unreal Plugin)와 UnrealLink(Rider Plugin)
> 유료이고 프로젝트 생성 후 처음 열면 인덱스 구성 등으로 몇 분정도 소요됨
#### 주의사항
- Microsoft Defender 제외 목록 추가 - 자동 선택
  ![](github_resources/MicrosoftDefender.png)
- RiderLink 플러그인 ***게임에 설치***
  - 엔진에 설치 선택 시 UE5는 오류 발생

# Plugins
- RiderLink
  - Unreal Editor에서 사용 가능한 Unreal과 Rider의 통합 개발 환경 지원 Plugin
- Cesium for Unreal
  - 3D Geospatial Plugin
- Pixel Streaming
  - Web Streaming Plugin

# Unreal Objects
- Blueprint
  - 노드 기반 인터페이스를 사용하는 완전한 게임플레이 스크립팅 시스템인 Blueprint Visual Scripting 시스템에서 사용하는 노드
- Actor
  - 카메라, 메시, 플레이어 스타트 위치 등과 같이 레벨에 배치할 수 있는 모든 오브젝트
  - 이동, 회전, 스케일링 등의 3D Transform을 지원하며 코드를 통해 생성 및 소멸이 가능함
- Component
  - 액터에 추가할 수 있는 기능 조각
- Pawn
  - 액터의 서브클래스이며 플레이어 또는 AI가 제어
- Character
  - 플레이어 캐릭터로 사용하기 위한 폰 액터의 서브클래스
  - 충돌, 이족보행 등을 위한 입력 바인딩, 플레이어가 제어하는 움직임을 위한 추가 코드 등이 제공됨
- Player Controller
  - 플레이어의 입력을 게임 안의 상호작용으로 변환
- Level
  - 개발자가 정의하는 게임플레이 영역. Geometry, Pawn, Actor 등 플레이어가 보고 상호작용할 수 있는 모든 것이 포함
  - 언리얼 엔진은 각 레벨을 별도의 *\*.umap* 파일로 저장하기 때문에 맵이라고도 함
- World
  - 게임을 구성하는 모든 레벨을 포함하는 컨테이너

# Naming Rules
- A: 액터를 상속받는 모든 클래스
- E: 열거형
- I: 추상 인터페이스
- S: SWidget을 상속받는 모든 클래스
- U: UObject를 상속받는 모든 클래스
- b: boolean 타입의 변수

# Plans
1. CesiumMap에서 Cesium for Unreal을 이용해 지도와 폰을 띄우고 실행
2. CharacterMap에서 C++ 클래스로 캐릭터 생성 후 동작 및 애니메이션 추가
3. BuoyancyMap에서 Buoyancy 전용 레벨을 새로 만들고 수위 조절 메뉴, buoyancy 설정값 조절 메뉴 추가
4. Map Switching UI 구현
5. exe 파일로 배포
6. Pixel Streaming을 이용해 Web Streaming

# Cesium for Unreal
- [Cesium for Unreal README.md](CesiumForUnreal.md)

# Character
- [Character README.md](Character.md)

# Buoyancy
- [Buoyancy README.md]()

# Map Switching
- [Map Switching README.md]()

# Exe Deployment

# Pixel Streaming

