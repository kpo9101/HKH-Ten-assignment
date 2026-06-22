# TIL

## 모듈 의존성

`TestActor.h`는 `AActor`를 공개적으로 상속하므로 `Test.Build.cs`의 `PublicDependencyModuleNames`에 `Core`, `CoreUObject`, `Engine`이 필요했다. 반대로 메인 모듈은 `TestActor.h`와 `TemporaryCharacterData.h`를 `.cpp`에서만 사용하므로 `ModuleAndPlugin.Build.cs`의 `PrivateDependencyModuleNames`에 `Test`, `Temporary`를 추가했다.

## 플러그인 활성화

플러그인은 `Plugins/Temporary/Temporary.uplugin`만 만든다고 자동으로 프로젝트에 포함되지 않는다. `.uproject`의 `Plugins` 배열에 `"Name": "Temporary", "Enabled": true`를 넣어야 빌드와 에디터 로딩 대상이 된다.

## Third Person 템플릿 이식

Third Person 템플릿은 `Content/ThirdPerson`만으로 끝나지 않는다. 캐릭터 블루프린트와 맵이 `Characters`, `LevelPrototyping` 공유 리소스를 참조하므로 해당 콘텐츠도 같이 복사해야 참조 누락을 피할 수 있다.

## 리다이렉트

템플릿 콘텐츠는 원래 `/Script/TP_ThirdPerson` 클래스를 바라본다. 현재 프로젝트의 모듈명은 `ModuleAndPlugin`이므로 `DefaultEngine.ini`에 `TP_ThirdPerson`에서 `/Script/ModuleAndPlugin`으로 가는 `ActiveGameNameRedirects`를 추가했다.
