
var config = {
    // top level keys are "tasks"
    multitask: {
        // these second level keys are subtasks in a multitask
        // How does it differentiate between subtatsks and options?
        subtarget: {
            file: "example.txt"
        }
    },
    // JSHint is leniant JSLint
    jshint: {
        files: ['Gruntfile.js', 'src/**/*.js']
    },
    watch: {
    },
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

// Mock target/task
//
// "this" is bound to the task object - I think
// The config for grunt is stored in grunt.config, but
// this is bound in the module exports function closure.
// How do we get access in a more global function?

function multitask( arg ) {
    console.log( this );

    // grunt is bound in the current env of the exports function
    // grunt.config.requires( 'file' );
    // this.requires( 'file' ); -- not work
    this.requiresConfig( 'multitask.subtarget.file' );
    console.log( "TARGET: " + arg );
}

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

   grunt.registerTask( 'multitask', multitask );
   grunt.registerTask( 'help', help );
   grunt.registerTask( 'nothing', nothing );
   grunt.registerTask( 'server', ['connect:server:keepalive'] );

   grunt.registerTask('default', ['help']);
};

// Task Object:
// { nameArgs: 'multitask:subtarget',
//   name: 'multitask',
//   args: [ 'subtarget' ],
//   flags: { subtarget: true },
//   async: [Function],
//   errorCount: [Getter],
//   requires: [Function: bound ],
//   requiresConfig: [Function],
//   options: [Function] }
//
// vim:autoindent expandtab sw=4
