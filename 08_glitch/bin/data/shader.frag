
uniform sampler2DRect rockImg;
uniform sampler2DRect lineImg;
uniform float time;

vec3 pal( in float t, in vec3 a, in vec3 b, in vec3 c, in vec3 d )
{
    // play with period and wavelength for different color results
    float period = 0.5;
    float wavelength = 1.;
    return a + b*cos( 6.28318*(c*t+d) * wavelength + period );
}

void main()
{
    vec2 pos = gl_FragCoord.xy;
    vec2 posOrig = pos;
    float res = 800.0; // make sure this is set resolution of sketch
    posOrig /= res;
    pos.y = 800. - pos.y;
    vec3 color = texture2DRect(rockImg, pos).rgb;
    
    // so many variables to play with
    float amt = sin(pos.x*.01 + time*1.) * 5. + 5.0;
    pos.x += (color.r*8.- 1.0) * amt;
    pos.y += (color.b*8. - 1.0) * amt;
    
    vec3 color2 = texture2DRect(lineImg, pos).rgb;
    
    posOrig.x += .1*time;
    
    
    if (color2.r < 1.0) {
        
        // Uncomment to try out different color pallettes from
        // https://www.iquilezles.org/www/articles/palettes/palettes.htm
        //        color2 = pal( posOrig.x, vec3(0.5,0.5,0.5),vec3(0.5,0.5,0.5),vec3(1.0,1.0,1.0),vec3(0.0,0.33,0.67) );
        color2 = pal( posOrig.x, vec3(0.5,0.5,0.5),vec3(0.5,0.5,0.5),vec3(1.0,1.0,1.0),vec3(0.0,0.10,0.20) );
        //        color2 = pal( posOrig.x, vec3(0.5,0.5,0.5),vec3(0.5,0.5,0.5),vec3(1.0,1.0,1.0),vec3(0.3,0.20,0.20) );
        //        color2 = pal( posOrig.x, vec3(0.5,0.5,0.5),vec3(0.5,0.5,0.5),vec3(1.0,1.0,0.5),vec3(0.8,0.90,0.30) );
        //        color2 = pal( posOrig.x, vec3(0.8,0.5,0.4),vec3(0.2,0.4,0.2),vec3(2.0,1.0,1.0),vec3(0.0,0.25,0.25) );
        
        // band
        float f = fract(posOrig.y*7.0);
        
    } else {
        color2.r = 1.0;
        color2.g = 1.0;
        color2.b = 1.0;
    }
    
    gl_FragColor = vec4(color2, 1.0);
    
}

