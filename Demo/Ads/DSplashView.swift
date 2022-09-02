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

class DSplashInstance: NSObject, BUSplashAdDelegate {
    var delegate: DSplashInstanceProtocol?
    
    lazy var splashAdInstance: BUSplashAd? = {
        let instance = BUSplashAd.init(slotID: "887901739", adSize: .init(width: UIScreen.main.bounds.size.width, height: UIScreen.main.bounds.size.height))
        return instance
    }()
    
     override init() {
         super.init()
        
         DispatchQueue.main.asyncAfter(deadline: .now() + 0.1) { [self] in
             if #available(iOS 14.0, *) {
                 ATTrackingManager.requestTrackingAuthorization { [self] status in
                     print("请求idfa状态 \(status)")
                     if status == .authorized {
                         DAdHandler.init()
                         print("idfa \(ASIdentifierManager.shared().advertisingIdentifier)")
                         
                         

                         if self.splashAdInstance != nil {
                             print("初始化广告位成功")
                         }

                         self.splashAdInstance?.delegate = self
                         self.splashAdInstance?.loadData()
                     }
                 }
             } else {
                 DAdHandler.init()

                 if self.splashAdInstance != nil {
                     print("初始化广告位成功")
                 }

                 self.splashAdInstance?.delegate = self
                 self.splashAdInstance?.loadData()
             }
         }
    }
    
    func splashAdLoadSuccess(_ splashAd: BUSplashAd) {
        print("广告加载成功")
    }
    
    func splashAdLoadFail(_ splashAd: BUSplashAd, error: BUAdError?) {
        print("广告加载失败 \(error?.userInfo)")
        delegate?.closeAd()
    }
    
    func splashAdRenderSuccess(_ splashAd: BUSplashAd) {
        print("广告加载渲染成功")
        if UIApplication.shared.rootViewController != nil {
            splashAd.showSplashView(inRootViewController: UIApplication.shared.rootViewController!)
        }
    }
    
    func splashAdRenderFail(_ splashAd: BUSplashAd, error: BUAdError?) {
        print("广告加载渲染失败")
        delegate?.closeAd()
    }
    
    func splashAdWillShow(_ splashAd: BUSplashAd) {
        print("广告将要显示")
    }
    
    func splashAdDidShow(_ splashAd: BUSplashAd) {
        print("广告已经显示")
    }
    
    func splashAdViewControllerDidClose(_ splashAd: BUSplashAd) {
        print("广告关闭")
        delegate?.closeAd()
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

protocol DSplashInstanceProtocol {
    func closeAd()
}

struct DSplashView: View, DSplashInstanceProtocol {
    @Binding var showAd: Bool
    private var adInstanse: DSplashInstance?
    
    init(showAd: Binding<Bool>) {
        self._showAd = showAd
        adInstanse = DSplashInstance()
        adInstanse?.delegate = self
    }
    
    func closeAd() {
        showAd = false
    }
    
    var body: some View {
        VStack {
            Color.clear
        }
    }
}

struct DSplashView_Previews: PreviewProvider {
    @State static var showAd: Bool = true
    
    static var previews: some View {
        DSplashView(showAd: $showAd)
    }
}
