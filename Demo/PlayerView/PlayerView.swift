//
//  PlayerView.swift
//  Demo
//
//  Created by wangyu on 2022/8/4.
//

import SwiftUI
import AVKit

class PlayerView: UIView {
    private var player = AVPlayer()
    private var asset: AVAsset!
    private var item: AVPlayerItem!
    private var playerController = AVPlayerViewController()
    
    deinit {
        player.removeObserver(self, forKeyPath: "status")
    }
    
    func setUrl(url: String?) {
//        asset = AVAsset(url: .init(string: url))
//
//        player.currentItem?.asset
//
//        player.pause()
        
        if (url != nil) {
            let _url = URL(fileURLWithPath: url!)
            asset = AVAsset(url: _url)
            
            asset.loadValuesAsynchronously(forKeys: ["tracks"]) { [self]
                var error: NSError?
                let status = self.asset.statusOfValue(forKey: "tracks", error: &error)
                print("加载状态 \(status) \(error)")
                switch(status) {
                case .loaded:
                    DispatchQueue.main.async {
                        self.item = AVPlayerItem(asset: self.asset)
//                        self.player = AVPlayer(playerItem: self.item)
                        self.playerController.player = self.player
                        
                        self.addSubview(self.playerController.view)
                        
                        self.item.addObserver(self, forKeyPath: "status", context: nil)
                        
//                        let avs = AVAudioSession()
//                        let ave = AVAudioEngine()
//                        let avpn = AVAudioPlayerNode.init()
//                        let avp = AVAudioPlayer()
//                        let avn = AVAudioNode()
//                        avs.setCategory(.soloAmbient, mode: .videoChat)
                    }
                case .unknown: break
                    
                case .loading: break
                    
                case .failed: break
                    
                case .cancelled: break
                    
                @unknown default: break
                    
                }
            }
        }
    }
    
    override func observeValue(forKeyPath keyPath: String?, of object: Any?, change: [NSKeyValueChangeKey : Any]?, context: UnsafeMutableRawPointer?) {
        print("status \(self.item.status)")
        if keyPath == "status" {
            if self.item.status == .readyToPlay {
                self.player.play()
            }
        }
    }
}

struct PlayerViewRepresent: UIViewRepresentable {
    func makeUIView(context: Context) -> UIView {
        let player = PlayerView()
        let url = Bundle.main.path(forResource: "sample", ofType: "mp4")
        player.setUrl(url: url)
        return player
    }
    
    func updateUIView(_ uiView: UIView, context: Context) {
        
    }
    
    typealias UIViewType = UIView
}
