//
//  DAlertView.swift
//  Demo
//
//  Created by wangyu on 2022/8/31.
//

import SwiftUI

final class DCoverView: UIViewRepresentable {
    typealias UIViewType = UIView
    func makeUIView(context: Context) -> UIView {
        let v = UIView()
        v.backgroundColor = .init(red: 0, green: 0, blue: 0, alpha: 0.4)
        return v
    }

    func updateUIView(_ uiView: UIView, context: Context) {

    }
}

struct DAlertView: View {
    @Environment(\.dismiss) private var dismiss
    
    @State private var isShowAlert: Bool = false
    @State private var inputValue: String = ""
    var body: some View {
        List {
            Button {
                isShowAlert = true
            } label: {
                Text("默认alert")
            }
            
            Button {
                showAlert { text in
                    print("alert text \(text)")
                    inputValue = text ?? ""
                }
            } label: {
                Text("UIKit Alert \(inputValue)")
            }
        }
        .alert("alert", isPresented: $isShowAlert) {
            Button("确定", role: .destructive) {
                isShowAlert = false
            }
            Button("取消", role: .cancel) {
                isShowAlert = false
            }
        } message: {
            Text("显示alert")
        }
    }
    
    func showAlert(success:@escaping (String?) -> ()) {
        let alert = UIAlertController(
            title: "Delete all data?",
            message: "All your data will be deleted!",
            preferredStyle: .alert)
        
        alert.addTextField { textField in
            textField.placeholder = "测试数据"
        }

        let moreOptionsAction = UIAlertAction(title: "确定", style: .default) { (text) in
            print("确定 \(text)")
            success(alert.textFields?.first?.text)
        }

        let cancelAction = UIAlertAction(title: "取消", style: .cancel, handler: nil)

        alert.addAction(moreOptionsAction)
        alert.addAction(cancelAction)

        UIApplication.shared.rootViewController?.present(alert, animated: true)
    }
}

struct DAlertView_Previews: PreviewProvider {
    static var previews: some View {
        DAlertView()
    }
}
