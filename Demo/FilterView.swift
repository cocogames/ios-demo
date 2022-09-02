//
//  FilterView.swift
//  Demo
//
//  Created by wangyu on 2022/8/18.
//

import SwiftUI

class ScrollPreferenceKey: PreferenceKey {
    static var defaultValue: CGFloat = 0
    
    static func reduce(value: inout CGFloat, nextValue: () -> CGFloat) {
        value += nextValue()
    }
}

struct FilterView: View {
    @State private var filterOffsetY = CGFloat.zero
    @State private var isShowTitle = false
    @State private var scrollToTop = false
    
    var body: some View {
        ZStack(alignment: .top) {
            ScrollView {
                ScrollViewReader { proxy in
                    VStack(spacing: 0) {
                        VStack {
                            HStack {
                                Text("测试")
                            }
                            HStack {
                                Text("测试")
                            }
                            HStack {
                                Text("测试")
                            }
                        }
                        .background(.blue)
                        .id(100000)
                        
                        GeometryReader { g in
                            Color.clear
                                .preference(key: ScrollPreferenceKey.self, value: g.frame(in: .named("scrollview")).minY)
                                .frame(height: 0)
                        }
                        .background(.yellow)
                        .frame(height: 0)
                        
                        VStack(spacing: 0) {
                            ForEach(0...100, id: \.self) { n in
                                Text(String(n))
                            }
                        }
                        .background(.red)
                    }
                    .onChange(of: scrollToTop, perform: { newValue in
                        if newValue {
                            withAnimation {
                                proxy.scrollTo(100000, anchor: .top)
                            }
                        }
                        scrollToTop = false
                    })
                }
            }
            .background(.green)
            .coordinateSpace(name: "scrollview")
            .onPreferenceChange(ScrollPreferenceKey.self) { value in
                print("scroll \(value)")
                
                if value < 0 {
                    withAnimation {
                        isShowTitle = true
                    }
                } else {
                    withAnimation {
                        isShowTitle = false
                    }
                }
            }
            
            if isShowTitle {
                VStack {
                    Color.gray
                }
                .frame(height: 48)
                .onTapGesture {
                    scrollToTop = true
                }
            }
            
        }
        .frame(maxWidth: .infinity)
        
    }
}

struct FilterView_Previews: PreviewProvider {
    static var previews: some View {
        FilterView()
    }
}
