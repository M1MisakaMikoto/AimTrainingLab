// // 引入必要的 Unreal Engine 类型
// import {
//     ALevelScriptActor,
//     FVector,
//     AActor,
//     APlayerController,
//     UUserWidget,
//     UWorld
// } from 'ue';

// // 获取现有关卡蓝图对应的类
// // 注意：需要替换为实际的关卡蓝图类路径
// const ExistingLevelBlueprintClass = require('Blueprint'/YourContentPath/ExistingLevelBlueprint') as typeof ALevelScriptActor;

// // 使用 mixin 扩展现有关卡蓝图
// @mixin(ExistingLevelBlueprintClass)
// class ExistingLevelBlueprintMixin {
//     // 重写 ReceiveBeginPlay 事件
//     ReceiveBeginPlay() {
//         // 调用原始的 ReceiveBeginPlay 函数
//         this.callSuper("ReceiveBeginPlay");

//         console.log("ExistingLevelBlueprintMixin: Level begin play!");

//         // 获取世界对象
//         const world: UWorld = Engine.GetWorld();
//         if (!world) {
//             console.error("World is not available.");
//             return;
//         }

//         // 获取第一个玩家控制器
//         const playerController: APlayerController = world.GetFirstPlayerController();
//         if (!playerController) {
//             console.error("Player controller is not available.");
//             return;
//         }

//         // 加载 UMG 蓝图类
//         // 注意：需要替换为你实际的 UMG 蓝图类路径
//         const widgetClass = require('Blueprint'/YourContentPath/SimpleCrosshairWidget') as typeof UUserWidget;
//         if (!widgetClass) {
//             console.error("Failed to load UMG widget class.");
//             return;
//         }

//         // 创建 UMG 控件实例
//         const widgetInstance: UUserWidget = UUserWidget.CreateWidget(playerController, widgetClass);
//         if (!widgetInstance) {
//             console.error("Failed to create UMG widget instance.");
//             return;
//         }

//         // 将控件添加到视口
//         widgetInstance.AddToViewport();
//     }
// }

// // 注册 mixin
// PuerTS.registerMixin(ExistingLevelBlueprintMixin);
