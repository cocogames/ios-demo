//
//  DAccountUIView.swift
//  Demo
//
//  Created by wangyu on 2022/8/5.
//

import SwiftUI
import AuthenticationServices

final class DAccountButton: UIViewRepresentable {
    func makeUIView(context: Context) -> ASAuthorizationAppleIDButton {
        return ASAuthorizationAppleIDButton()
    }
    
    func updateUIView(_ uiView: ASAuthorizationAppleIDButton, context: Context) {
        
    }
}

class SignInWithAppleDelegates: NSObject, ASAuthorizationControllerDelegate {
    func authorizationController(controller: ASAuthorizationController, didCompleteWithError error: Error) {
        print("认证错误 \(error)")
    }
    
    func authorizationController(controller: ASAuthorizationController, didCompleteWithAuthorization authorization: ASAuthorization) {
        print("认证成功 \(authorization)")
        guard let credential = authorization.credential as? ASAuthorizationAppleIDCredential else { return }
        print("认证成功 \(credential.fullName)")
        print("认证成功 \(credential.authorizationCode)")
        print("认证成功 \(credential.user)")
    }
}
