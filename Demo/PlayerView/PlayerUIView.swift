//
//  PlayerUIView.swift
//  Demo
//
//  Created by wangyu on 2022/8/4.
//

import SwiftUI

struct PlayerUIView: View {
    var body: some View {
        VStack {
            PlayerViewRepresent()
            
            Button {
                print("选择")
            } label: {
                Text("低音")
            }
            .frame(width: 200, height: 100)
            .background(Color.blue)
        }
    }
}

struct PlayerUIView_Previews: PreviewProvider {
    static var previews: some View {
        PlayerUIView()
    }
}
