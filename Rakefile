require 'rake/testtask'

begin
  require 'jeweler'

  Jeweler::Tasks.new do |gemspec|
    gemspec.name = "nnls"
    gemspec.summary = "Non-negative Less Square Algorithm"
    gemspec.description = "Ruby bindings for C. Lawson and R. Hanson 'Non-negative Less Square' algorithm implementation."
    gemspec.email = "sotakone@sotakone.com"
    gemspec.homepage = "http://github.com/sotakone/nnls/"
    gemspec.authors = ["Mikhail Lapshin"]
    gemspec.files.include 'lib/nnls.rb'
    gemspec.files.include 'ext/nnls/*.c'
    gemspec.files.include 'ext/nnls/extconf.rb'
  end

  Jeweler::GemcutterTasks.new
rescue LoadError
  puts "Jeweler not available. Install it with: gem install jeweler"
end

Rake::TestTask.new(:test) do |t|
  t.test_files = FileList['test/*_test.rb']
end
