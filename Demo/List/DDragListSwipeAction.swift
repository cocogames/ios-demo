//
//  DDragListSwipeAction.swift
//  Demo
//
//  Created by wangyu on 2022/8/31.
//

import SwiftUI

struct DDragListSwipeAction: View {
    @State var datas: [(String,[String])] = [("诗歌", ["黄瓜不只", "是黄瓜", "今天天气", "还是不错的"]),
                                             ("古诗词", ["床前明月光", "疑是地上霜", "举头望明月", "低头思故乡"])]
    var body: some View {
        List {
            ForEach(datas.indices, id: \.self) { index in
                Section(datas[index].0) {
                    var subs = datas[index].1
                    ForEach(subs, id: \.self) { sub in
                        Text(sub)
                            .onDrag {
                                let provider = NSItemProvider.init(object: NSString(string: sub))
                                return provider
                            }
                            .swipeActions(edge: .trailing, allowsFullSwipe: true) {
                                Button {
                                    let offset = subs.firstIndex(of: sub)
                                    subs.remove(at: offset!)
                                    datas[index].1 = subs
                                } label: {
                                    Image(systemName: "trash")
                                }
                                .tint(.red)
                                
                                Button {
                                    print("edit")
                                } label: {
                                    Image(systemName: "square.and.pencil")
                                }
                                .tint(.orange)
                            }
                    }
                    .onMove { fromSet, to in
                        subs.move(fromOffsets: fromSet, toOffset: to)
                        datas[index].1 = subs
                    }
                }
            }
        }
    }
}

struct DDragListSwipeAction_Previews: PreviewProvider {
    static var previews: some View {
        DDragListSwipeAction()
    }
}
