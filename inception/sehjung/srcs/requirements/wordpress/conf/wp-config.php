/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

/* default db settings */
define( 'DB_HOST', 'mariadb' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */

/**#@-*/
/* insert keys here */
/* my own key!! */
define('AUTH_KEY',         'JZl06:gHa0X7`W!>dHJ&X+UNl%vRX*:c!T|o50^^J$eq=J?|0>j+s-y=jwyilZxc');
define('SECURE_AUTH_KEY',  ' 0KS$[08crv=T~-x=wkI-R_+VD>O{D^@i( OaGwV|OY+]8zr+_m}G1cD |(Xq*72');
define('LOGGED_IN_KEY',    'gptIvp254+Aj9WXT>6IKM8 Vs6z8PI< 5+&,8D|OMRWWoZM?QOJ@sgc*1*,r&hB#');
define('NONCE_KEY',        '_2t,=9~+flMw.OIMN;$d:J3w^`0vi9@|=v,RNkYf{L5Mi}rTk4OwzFh|5O0$qd$:');
define('AUTH_SALT',        'AgD+PCSltTmZB;d|7+h$<A0cEr!GDSHPWBn^I~`$HHr&_NZt+&OejX-oB8hE6uj=');
define('SECURE_AUTH_SALT', 'A|lvT_!#u8wE8t;`-BFb>^*k1dd(OUQ;+nv9C]+S}@W{#-&q63pkES?F4BJ+uRO*');
define('LOGGED_IN_SALT',   'm#b3q<[,KUy3>QR&XldMBQ^u{q!g|TmF957Ll-:~||y4i_~fK6FUv&:^{G)jg}|t');
define('NONCE_SALT',       'sMgVw$<x|wVQrP/j~TDboKo4kU=|>KhQ)mw6W<%!.[A[(%Zz^:t&/!+T^]YvmvxQ');
/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
