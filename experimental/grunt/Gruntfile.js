
var config = {
    jshint: {
        files: ['Gruntfile.js', 'src/**/*.js']
    },
    watch: {},
    connect: {
        server: {
            options: {
                port: 9000,
                hostname: 'localhost',
                base: ['dist/']
            }
        }
    }
};

function help() {
    console.log( "No tasks defined yet." );
}

function nothing() {
    console.log( "what me worry" );
}

module.exports = function (grunt) {
   grunt.initConfig( config );

   // With this line you get this error:
   //   Warning: Task "jshint" not found. Use --force to continue.
   grunt.loadNpmTasks( 'grunt-contrib-jshint' );
   grunt.loadNpmTasks( 'grunt-contrib-watch' );
   grunt.loadNpmTasks( 'grunt-contrib-connect' );

   grunt.registerTask( 'help', help );
   grunt.registerTask( 'nothing', nothing );
   grunt.registerTask( 'server', ['connect:server:keepalive'] );

   grunt.registerTask('default', ['help']);
};

// vim:autoindent expandtab sw=4
