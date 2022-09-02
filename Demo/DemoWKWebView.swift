//
//  DemoWKWebView.swift
//  Demo
//
//  Created by wangyu on 2022/8/2.
//

import SwiftUI
import UIKit

struct DemoWKWebView: View {
//    @State var url = "http://192.168.35.89:8808"
    @State var url = Bundle.main.path(forResource: "index", ofType: "html") ?? ""
    
    var body: some View {
        WebView(url: $url)
            .navigationTitle("")
            .navigationBarTitleDisplayMode(.inline)
    }
}

struct DemoWKWebView_Previews: PreviewProvider {
    static var previews: some View {
        DemoWKWebView()
    }
}
