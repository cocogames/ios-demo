//
//  DemoApp.swift
//  Demo
//
//  Created by wangyu on 2022/8/2.
//

import SwiftUI

@main
struct DemoApp: App {
    @State var showAd: Bool = false
    
    init() {
        let tabbarAppearance = UITabBarAppearance()
        tabbarAppearance.configureWithOpaqueBackground()
        tabbarAppearance.backgroundColor = .white
        UITabBar.appearance().standardAppearance = tabbarAppearance
        
        let navibarAppearance = UINavigationBarAppearance()
        navibarAppearance.configureWithOpaqueBackground()
        navibarAppearance.backgroundColor = .white
        UINavigationBar.appearance().standardAppearance = navibarAppearance
        UINavigationBar.appearance().scrollEdgeAppearance = navibarAppearance
    }
    
    var body: some Scene {
        WindowGroup {
            if showAd == true {
                DSplashView(showAd: $showAd)
            } else {
                ContentView()
                    .preferredColorScheme(.light)
            }
        }
    }
}

extension UIApplication {
  var currentKeyWindow: UIWindow? {
    UIApplication.shared.connectedScenes
      .filter { $0.activationState == .foregroundActive }
      .map { $0 as? UIWindowScene }
      .compactMap { $0 }
      .first?.windows
      .filter { $0.isKeyWindow }
      .first
  }

  var rootViewController: UIViewController? {
    currentKeyWindow?.rootViewController
  }
}
