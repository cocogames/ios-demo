//
//  ContentView.swift
//  Demo
//
//  Created by wangyu on 2022/8/2.
//

import SwiftUI

struct ContentView: View {
    init() {
        
    }
    
    var body: some View {
        NavigationView {
//            VStack(spacing: 0) {
//                Color.white
//                    .frame(height: 1)
//                    .frame(maxWidth: .infinity)
//
//
//            }
            VStack {
                List {
                    NavigationLink(destination: DemoWKWebView()) {
                        Text("WKWebView")
                    }
                    
                    NavigationLink(destination: PlayerUIView()) {
                        Text("播放器")
                    }
                    
                    NavigationLink(destination: DAccountView()) {
                        Text("登录")
                    }
                    
                    NavigationLink(destination: WrapView()) {
                        Text("换行")
                    }
                    
                    NavigationLink(destination: FilterView()) {
                        Text("滚动界面")
                    }
                    
                    NavigationLink(destination: DList()) {
                        Text("列表")
                    }
                    
                    NavigationLink(destination: DAlertView()) {
                        Text("Alert")
                    }
                }
            }
            .navigationBarTitleDisplayMode(.inline)
            .navigationTitle("首页")
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
