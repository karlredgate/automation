
class Widget extends HTMLElement {
    constructor() {
	super();
	var shadowRoot = this.attachShadow( {mode: 'open'} );
	shadowRoot.innerHTML = '<h1>shadow dom</h1>';
    }
    connectedCallback() {
    }
    disconnectedCallback() {
    }
    attributeChangedCallback( attribute_name, old_value, new_value ) {
    }
    adoptedCallback() {
    }
    // observedAttribute ??
    set size( value ) {
	this.setAttribute( "size", value );
    }
    get size() {
	return this.hasAttribute( "size" );
    }
}

window.customElements.define( 'custom-widget', Widget );

