Pod::Spec.new do |s|
  s.name             = 'libpomelo2'
  s.version          = '0.5.0'
  s.summary          = 'The missing pod for libpomelo2 with ssl support!'

  s.description      = <<-DESC
    The missing pod for libpomelo2 with ssl support!
  DESC

  s.homepage         = 'https://github.com/felipejfc/libpomelo2_pod'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Felipe Cavalcanti' => 'fjfcavalcanti@gmail.com' }
  s.source           = { :git => 'https://github.com/felipejfc/libpomelo2_pod.git', :tag => s.version.to_s }

  s.ios.deployment_target = '7.0'

  s.source_files = ['src/**/*', 'include/**/*']
  
  s.dependency 'OpenSSL', '~> 1.0.208'
  s.dependency 'libuv', '~> 1.4.0'

end
