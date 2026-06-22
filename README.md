# ModuleAndPlugin 과제 정리

Unreal Engine 5.5 C++ 프로젝트에서 모듈과 플러그인을 직접 구성하고 연결하는 과제입니다. 기본 Third Person 템플릿 위에 `Test` 모듈과 `Temporary` 플러그인을 추가했으며, 실행 시 두 구조가 모두 동작하는 것을 화면 메시지로 확인할 수 있습니다.

## 구현 체크리스트

- Third Person C++ 템플릿 이식
  - `Content/ThirdPerson` 맵, 입력, 캐릭터 블루프린트 추가
  - `Content/Characters`, `Content/LevelPrototyping` 공유 리소스 추가
  - `TP_ThirdPersonCharacter`, `TP_ThirdPersonGameMode` C++ 클래스 추가
  - 기본 맵과 기본 게임모드를 Third Person 맵/게임모드로 설정

- `Test` 모듈 구성
  - `Source/Test/Test.Build.cs`
  - `Source/Test/Public/Test.h`
  - `Source/Test/Private/Test.cpp`
  - `Source/Test/Public/TestActor.h`
  - `Source/Test/Private/TestActor.cpp`
  - `ModuleAndPlugin.Target.cs`, `ModuleAndPluginEditor.Target.cs`, `.uproject`에 `Test` 등록

- 모듈 간 상호작용
  - 메인 모듈의 `TP_ThirdPersonCharacter::BeginPlay`에서 `ATestActor`를 스폰
  - `ATestActor::BeginPlay`에서 로그와 화면 메시지 출력

- `Temporary` 플러그인 구성
  - `Plugins/Temporary/Temporary.uplugin`
  - `Plugins/Temporary/Source/Temporary/Temporary.Build.cs`
  - `StartupModule`, `ShutdownModule` 로그 구현
  - `CanContainContent: true`로 플러그인 콘텐츠 폴더 활성화
  - `.uproject`의 `Plugins` 항목에서 `Temporary` 활성화

- 도전 기능
  - `UTemporaryCharacterData : UObject` 추가
  - `BlueprintType`, `Blueprintable`로 블루프린트 사용 가능하게 노출
  - 캐릭터 `BeginPlay`에서 `UTemporaryCharacterData`를 생성하고 `DisplayName`, `Level`, `Health` 값을 화면에 출력

## 주요 폴더 구조

```text
ModuleAndPlugin/
  Config/
    DefaultEngine.ini
  Content/
    ThirdPerson/
    Characters/
    LevelPrototyping/
  Plugins/
    Temporary/
      Content/
      Source/Temporary/
  Source/
    ModuleAndPlugin/
      TP_ThirdPersonCharacter.*
      TP_ThirdPersonGameMode.*
    Test/
      Public/
      Private/
```
