//
//  DSplashView.swift
//  Demo
//
//  Created by wangyu on 2022/8/25.
//

import SwiftUI
import BUAdSDK
import AdSupport
import AppTrackingTransparency

final class DSplashViewRepresent: NSObject, UIViewControllerRepresentable {
    typealias UIViewControllerType = UIViewController
    
    @Binding var showAd: Bool
    private var splashAd: BUSplashAd?
    
    init(showAd: Binding<Bool>) {
        self._showAd = showAd
    }
    
    func updateUIViewController(_ uiViewController: UIViewControllerType, context: Context) {
        
    }
    
    func makeUIViewController(context: Context) -> UIViewController {
        let vc = UIViewController()
        
        print("size is \(UIScreen.main.bounds.size)")
        
        DispatchQueue.main.asyncAfter(deadline: .now() + 0.1) {
            if #available(iOS 14.0, *) {
                ATTrackingManager.requestTrackingAuthorization { status in
                    print("请求idfa状态 \(status)")
                    if status == .authorized {
                        DAdHandler.init()
                        print("idfa \(ASIdentifierManager.shared().advertisingIdentifier)")
                        
                        self.initSlot(context: context)
                    }
                }
            } else {
                DAdHandler.init()
                
                self.initSlot(context: context)
            }
        }
        
        return vc
    }
    
    func initSlot(context: Context) {
        splashAd = BUSplashAd.init(slotID: "887901739", adSize: .init(width: UIScreen.main.bounds.size.width, height: UIScreen.main.bounds.size.height))

        if splashAd != nil {
            print("初始化广告位成功")
        }

        self.splashAd?.delegate = context.coordinator
        self.splashAd?.loadData()
    }
    
    func makeCoordinator() -> Coordinator {
        return Coordinator(controller: self)
    }
    
    class Coordinator: NSObject, BUSplashAdDelegate {
        var controller: DSplashViewRepresent
        
        init(controller: DSplashViewRepresent) {
            self.controller = controller
        }
        
        func splashAdLoadSuccess(_ splashAd: BUSplashAd) {
            print("广告加载成功")
        }
        
        func splashAdLoadFail(_ splashAd: BUSplashAd, error: BUAdError?) {
            print("广告加载失败 \(error?.userInfo)")
        }
        
        func splashAdRenderSuccess(_ splashAd: BUSplashAd) {
            print("广告加载渲染成功")
            if UIApplication.shared.rootViewController != nil {
                splashAd.showSplashView(inRootViewController: UIApplication.shared.rootViewController!)
            }
        }
        
        func splashAdRenderFail(_ splashAd: BUSplashAd, error: BUAdError?) {
            print("广告加载渲染失败")
        }
        
        func splashAdWillShow(_ splashAd: BUSplashAd) {
            print("广告将要显示")
        }
        
        func splashAdDidShow(_ splashAd: BUSplashAd) {
            print("广告已经显示")
        }
        
        func splashAdViewControllerDidClose(_ splashAd: BUSplashAd) {
            print("广告关闭")
            controller.showAd = false
        }
        
        func splashDidCloseOtherController(_ splashAd: BUSplashAd, interactionType: BUInteractionType) {
            print("广告关闭其他")
        }
        
        func splashVideoAdDidPlayFinish(_ splashAd: BUSplashAd, didFailWithError error: Error) {
            print("广告播放完成")
        }
        
        func splashAdDidClick(_ splashAd: BUSplashAd) {
            print("广告点击")
        }
        
        func splashAdDidClose(_ splashAd: BUSplashAd, closeType: BUSplashAdCloseType) {
            print("广告关闭")
        }
    }
}

struct DSplashViewByView: View {
    @Binding var showAd: Bool
    
    var body: some View {
        ZStack {
            Color.gray
            
            DSplashViewRepresent(showAd: $showAd)
                .frame(maxWidth: .infinity)
        }
        .ignoresSafeArea()
    }
}

struct DSplashViewByView_Previews: PreviewProvider {
    @State static var showAd: Bool = true
    
    static var previews: some View {
        DSplashViewByView(showAd: $showAd)
    }
}
