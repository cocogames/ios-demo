//
//  DList.swift
//  Demo
//
//  Created by wangyu on 2022/8/31.
//

import SwiftUI

struct DList: View {
    var body: some View {
        List {
            NavigationLink(destination: DDragList()) {
                Text("列表编辑模式")
            }
            
            NavigationLink(destination: DDragListSwipeAction()) {
                Text("列表项横滑编辑")
            }
        }
    }
}

struct DList_Previews: PreviewProvider {
    static var previews: some View {
        DList()
    }
}
