<?xml version='1.0' ?>
<xsl:stylesheet xmlns:xsl='http://www.w3.org/1999/XSL/Transform'
                xmlns:fn='http://www.w3.org/2005/02/xpath-functions'
                xmlns:xsd='http://www.w3.org/2001/XSL/XMLSchema'
                xmlns:xsi='http://www.w3.org/2001/XSL/XMLSchema-instance'
                xmlns:dc="http://purl.org/dc/elements/1.1/"
                xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"
                xmlns:rdfs="http://www.w3.org/2000/01/rdf-schema#"
                xmlns:so="http://schema.org/"
                version='1.0'>

  <xsl:output method="xml" indent="yes" omit-xml-declaration="yes" />
  <xsl:param name='base' />
  <xsl:param name='catalog' />

  <dc:title></dc:title>
  <dc:creator>Karl N. Redgate</dc:creator>
  <dc:description>
  </dc:description>

  <xsl:template match='text()' />

  <xsl:template match='/'>
      <!-- <xsl:element name='rdf:RDF'> -->
        <xsl:apply-templates />
      <!-- </xsl:element> -->
      <xsl:text>&#10;</xsl:text>
  </xsl:template>

  <xsl:template match='div[@class="product single-item"]'>
      <xsl:element name='so:Product'>
         <xsl:attribute name='rdf:about'>
         </xsl:attribute>

         <xsl:element name='so:sku'>
             <xsl:value-of select='@data-sku' />
         </xsl:element>
        <xsl:text>&#10;</xsl:text>
        <xsl:apply-templates />
      </xsl:element>
        <xsl:text>&#10;</xsl:text>
  </xsl:template>

  <dc:description>
    This matches the 'product' div and produces a set of triples about the
    product in the resulting RDF.

    The base string param should be deducible from the base document URI.
    Not sure how to get that yet.  It looks like a XSLT 2.0 feature, but I
    think I have been able to do this before - need to check.
  </dc:description>
  <xsl:template match='div[@class="product "]'>
      <xsl:element name='so:Product'>
         <xsl:attribute name='rdf:about'>
             <xsl:value-of select='$base' />
             <xsl:value-of select='ul[@class="productDescription"]/li[@class="productName"]/a/@href' />
         </xsl:attribute>

         <xsl:element name='so:sku'>
             <xsl:value-of select='@data-sku' />
         </xsl:element>
        <xsl:text>&#10;</xsl:text>
        <xsl:apply-templates />
      </xsl:element>
      <xsl:text>&#10;</xsl:text>
  </xsl:template>

  <xsl:template match='ul[@class="productDescription"]'>

      <xsl:element name='so:brand'>
          <xsl:value-of select='normalize-space( li[@class="productBrand"] )' />
      </xsl:element>

      <xsl:element name='so:name'>
          <xsl:value-of select='normalize-space( li[@class="productName"] )' />
      </xsl:element>

      <xsl:text>&#10;</xsl:text>
      <xsl:apply-templates />
  </xsl:template>

  <xsl:template match='span[@class="gcprice gcprice-regular"]'>
      <xsl:element name='so:price'>
          <xsl:value-of select='normalize-space( . )' />
      </xsl:element>
  </xsl:template>

</xsl:stylesheet>
<!-- vim: set autoindent expandtab sw=4 syntax=xslt: -->
