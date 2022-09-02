//
//  WebView.swift
//  Demo
//
//  Created by wangyu on 2022/8/2.
//

import SwiftUI
import WebKit

struct WebView: UIViewRepresentable {
    @Binding var url: String
        
    class WebViewScriptMessageDelegate: NSObject, WKScriptMessageHandler {
        private var delegate: WKWebView!
        
        init(delegate: WKWebView) {
            self.delegate = delegate
        }
        
        func userContentController(_ userContentController: WKUserContentController, didReceive message: WKScriptMessage) {
            print("收到消息 \(message.body)")
            guard let dic = message.body as? Dictionary<String, String> else {
                return
            }
            
            let res = [
                "name": "wisetv"
            ]
            guard let data = try? JSONSerialization.data(withJSONObject: res, options: .prettyPrinted) else { return }
            let str = String(data: data, encoding: .utf8)
            
            let callbackstr = "wisetv.callback('\(dic["success"]!)',\(str!))"
            
            print("callback is \(callbackstr)")
            
            delegate.evaluateJavaScript(callbackstr)
        }
    }
    
    func makeUIView(context: Context) -> WKWebView {
        let webConfig = WKWebViewConfiguration()
        webConfig.preferences = WKPreferences()
        webConfig.preferences.javaScriptCanOpenWindowsAutomatically = true
        webConfig.defaultWebpagePreferences.allowsContentJavaScript = true
        webConfig.processPool = WKProcessPool()
        
        let webView = WKWebView(frame: .zero, configuration: webConfig)
        
        let webViewScriptMessageHandler = WebViewScriptMessageDelegate(delegate: webView)
        
        webView.configuration.userContentController.add(webViewScriptMessageHandler, name: "wisetv")
        return webView
    }
    
    func updateUIView(_ webView: WKWebView, context: Context) {
//        let request = URLRequest(url: .init(string: self.url)!)
//        webView.load(request)
        webView.loadFileURL(URL.init(fileURLWithPath: self.url), allowingReadAccessTo: URL.init(fileURLWithPath: self.url))
    }
}
