<?xml version='1.0' ?>
<xsl:stylesheet xmlns:xsl='http://www.w3.org/1999/XSL/Transform'
                xmlns:fn='http://www.w3.org/2005/02/xpath-functions'
                xmlns:xsd='http://www.w3.org/2001/XSL/XMLSchema'
                xmlns:xsi='http://www.w3.org/2001/XSL/XMLSchema-instance'
                xmlns:dc="http://purl.org/dc/elements/1.1/"
                version='1.0'>

  <xsl:output method="text"/>

  <dc:title>Extract Google Chrome Bookmarks</dc:title>
  <dc:creator>Karl Redgate</dc:creator>
  <dc:description>
  </dc:description>

  <xsl:template match='text()' />

  <xsl:template match='g[key=type][following-sibling::val=url]'>
      <xsl:text>URL: </xsl:text>
      <xsl:value-of select='val[../preceding-sibling::key=url]' />
      <xsl:text>&#10;</xsl:text>
  </xsl:template>

  <xsl:template match='a[substring(@href,string-length(@href)-3,4) = ".xml"]'>
      <xsl:text>xsltproc http://redgates.com/storbitz/trunk/style/sb2dns.xslt </xsl:text>
      <xsl:text>http://redgates.com/storbitz/trunk/xml/</xsl:text>
      <xsl:value-of select='.' />
      <xsl:text>&#10;</xsl:text>
  </xsl:template>

</xsl:stylesheet>
<!--
  vim:autoindent
  vim:expandtab
  -->
