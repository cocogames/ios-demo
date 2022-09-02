//
//  DDragList.swift
//  Demo
//
//  Created by wangyu on 2022/8/30.
//

import SwiftUI

struct DDragList: View {
    @State var datas: [(String,[String])] = [("诗歌", ["黄瓜不只", "是黄瓜", "今天天气", "还是不错的"]),
                                             ("古诗词", ["床前明月光", "疑是地上霜", "举头望明月", "低头思故乡"])]
    @State var editMode: EditMode = .inactive
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
                    }
                    .onMove { fromSet, to in
                        subs.move(fromOffsets: fromSet, toOffset: to)
                        datas[index].1 = subs
                    }
                    .onDelete { indexSet in
                        subs.remove(atOffsets: indexSet)
                        datas[index].1 = subs
                    }
                }
            }
        }
        .environment(\.editMode, $editMode)
        .onAppear {
            editMode = .active
        }
        .onDisappear {
            editMode = .inactive
        }
    }
}

struct DDragList_Previews: PreviewProvider {
    static var previews: some View {
        DDragList()
    }
}
