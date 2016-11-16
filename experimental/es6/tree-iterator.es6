
class BinaryTree {
    constructor( value, left=null, right=null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }

    //
    // What the @#$#$ is this syntax
    //
    * [Symbol.iterator]() {
        yield this.value;
        if ( this.left ) {
            yield* this.left;
        }
        if ( this.right ) {
            yield* this.right;
        }
    }
}

// vim:autoindent expandtab sw=4
