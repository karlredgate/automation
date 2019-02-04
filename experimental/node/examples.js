
/^darwin/.test(process.platform);
/^win/.test(process.platform);

process.env[/^win/.test(process.platform) ? 'USERPROFILE' : 'HOME'];
