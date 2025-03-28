# ✨개요
1. 플러그인을 구현하고 패키징해서 이후 협업 시 작업물을 간편하게 공유할 수 있도록 합니다.
2. 게임인스턴스서브시스템을 이용하여 레벨 이동 시에도 저장한 값을 유지하여 계속해서 사용할 수 있도록 합니다.
---
---
# 🕹기능
MyIDPlugin
+ SetUserName : MyIDPlugin 모듈에 있는 UserName의 값을 할당합니다.
+ GetUserName : UserName에 할당된 값을 반환합니다.
MyGameInstanceSubsystem
+ SetUserInstanceName : MyGameInstanceSubsystem 에 있는 UserName의 값을 할당합니다.
+ GetUserInstanceName : UserName에 할당된 값을 반환합니다.
---
---
# 📃플러그인의 구현 및 배포
### 1. 플러그인 추가
+ 언리얼 에디터를 켜서 상단 메뉴의 편집 -> 플러그인 -> 추가(Add) 버튼을 눌러 추가할 수 있다.
![image](https://github.com/user-attachments/assets/11e1262a-e545-4f7e-bd85-3e1f3d10d448)
---
class UMyIDPluginBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "MyIDPlugin sample test testing"), Category = "MyIDPluginTesting")
	static float MyIDPluginSampleFunction(float Param);

public:
	static FString UserName;

	UFUNCTION(BlueprintCallable, Category = "MyPluginCategory")
	static void SetUserName(const FString& NewName);

	UFUNCTION(BlueprintPure, Category = "MyPluginCategory")
	static FString GetUserName();
};

---
+ 위의 코드와 같이 static으로 함수와 변수를 만들어 블루프린트에서 사용할 수 있도록 한다.

---
### 2. 플러그인 사용
![image](https://github.com/user-attachments/assets/9b6d68c8-d6e1-4529-ab88-80188285435b)
+ 플러그인의 함수를 이용하여 블루프린트를 작성한다.

![image](https://github.com/user-attachments/assets/165aefc9-0957-48d0-9e57-6826d68a8c7a)
+ 실행하게되면 플러그인을 통해 값을 저장하고 출력하는 로직이 제대로 작동함을 알 수 있다.

---
### 3. 플러그인 배포
+ 플러그인의 배포를 위해 다시 플러그인을 추가할 때의 메뉴로 들어가서 배포할 플러그인을 찾는다.
![image](https://github.com/user-attachments/assets/6f63cda4-54dd-4751-8776-be5166440edd)

+ 패키지 버튼을 눌러서 저장하고 싶은 위치에 플러그인을 저장한다.
![image](https://github.com/user-attachments/assets/d5d19e14-f8b8-4dea-8abc-ba199ffe1b51)

---
---
# 🧾게임인스턴스서브시스템 구현
### 1. 게임인스턴스서브시스템 추가
+ 게임인스턴스서브시스템 클래스를 추가한다.
![image](https://github.com/user-attachments/assets/43cd6e6f-fd1f-4b00-a4bb-60a4a2bb9cc8)

---
class CH4_PLUGINPROJECT_API UMyGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable, Category = "User Data")
    void SetUserInstanceName(const FString& NewName);

    UFUNCTION(BlueprintPure, Category = "User Data")
    FString GetUserInstanceName() const;

private:
    FString UserName;
};

---
+ 플러그인과 마찬가지로 게임인스턴스서브시스템을 이용해 사용할 함수와 변수를 추가하고 블루프린트에서 사용할 수 있도록한다.

---
### 2. 게임인스턴스서브시스템 사용
+ GetGameInstanceSubsystem 을 이용하여 나의 게임인스턴스서브시스템를 가져와 값을 저장하는 노드를 작성한다.
![image](https://github.com/user-attachments/assets/43d3451d-5326-4119-a0db-6091beafc661)

+ 레벨 이동을 테스트하기 위해 N키를 누르면 이동하는 노드를 작성했다.
+ ![image](https://github.com/user-attachments/assets/33cd04b6-99be-4e63-87de-39e9f611e23c)

+ 이동 할 레벨에는 저장하는 값 없이 가져와 출력만하는 노드를 작성한다.
![image](https://github.com/user-attachments/assets/74756b59-fb6b-49da-a051-55b2ba9eb951)

+ 레벨을 이동한 후 출력했을 때 디폴트 값이 아닌 이전 레벨에서 저장된 값이 나오는 것을 확인할 수 있다.
![image](https://github.com/user-attachments/assets/1eddb226-e876-4f80-a11e-c6ec4a0c1a70)



