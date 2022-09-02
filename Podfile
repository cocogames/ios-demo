workspace 'Demo.xcworkspace'

project 'Demo.xcodeproj'
target 'Demo' do
   platform :ios, '10.0'
   inhibit_all_warnings!
   project 'Demo.xcodeproj'
   
   pod 'Ads-CN' , :subspecs => ['BUAdSDK_Compatible']
   
end

post_install do |installer|
    installer.pods_project.targets.each do |target|
        target.build_configurations.each do |config|
          if config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'].to_f < 10.0
            config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '10.0'
          end
        end
    end
end


