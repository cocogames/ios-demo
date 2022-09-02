//
//  WrapView.swift
//  Demo
//
//  Created by wangyu on 6022/8/16.
//

import SwiftUI

struct WrapView: View {
    @State var sections: [String: [String]] = [
        "季节": ["春","夏","秋","冬"],
        "品牌": ["李宁","nick","adidas","安踏"],
    ]
    
    var body: some View {
        VStack {
            
        }
//        ScrollView {
//            ForEach(sections.keys, id: \.self) { key in
//                HStack {
//                    Text(key)
//
//                    WrappingHStack(sections[key]!, id: \.self, lineSpacing: 10) { p in
//                        Text(p)
//                            .padding(4)
//                            .background(.orange)
//                            .cornerRadius(4)
//                    }
//                }
//            }
//        }
//        .padding(20)
    }
}

struct WrapView_Previews: PreviewProvider {
    static var previews: some View {
        WrapView()
    }
}
