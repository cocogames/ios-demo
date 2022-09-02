//
//  DAccount.swift
//  Demo
//
//  Created by wangyu on 2022/8/5.
//

import SwiftUI
import AuthenticationServices

struct DAccountView: View {
    var delegate:SignInWithAppleDelegates =  SignInWithAppleDelegates()
    
    var body: some View {
        DAccountButton()
            .frame(width: 280, height: 60)
            .onTapGesture(perform: showAppleLogin)
    }
    
    private func showAppleLogin() {
        let request = ASAuthorizationAppleIDProvider().createRequest()
        request.requestedScopes = [.fullName]
        let controller = ASAuthorizationController(authorizationRequests: [request])
        controller.delegate = self.delegate
        controller.performRequests()
    }
}

struct DAccountView_Previews: PreviewProvider {
    static var previews: some View {
        DAccountView()
    }
}
