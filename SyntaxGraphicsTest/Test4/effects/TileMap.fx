string description = "Basic 2d sprite";

//------------------------------------
float4x4 worldViewProj : WorldViewParallel;
//x is width of a tile. z is width of a map entry.
//float4 tileSize = float4(1.0f,0.0f,0.015625f,0.0f); 
float4 tileSize : TileSize
< string Type = "Material"; >; 

texture tilesTexture : Texture0;
texture mapTexture : Texture1;

//------------------------------------
struct vertexInput {
    float3 position				: POSITION;
    float2 texCoord				: TEXCOORD0;
};

struct vertexOutput {
    float4 hPosition		: POSITION;
    float2 texCoordDiffuse	: TEXCOORD0;
};


//------------------------------------
vertexOutput VS_TransformAndFrame(vertexInput IN) 
{
    vertexOutput OUT;
    OUT.hPosition = mul( float4(IN.position.xyz , 1.0) , worldViewProj);
    OUT.texCoordDiffuse = IN.texCoord;
    return OUT;
}


//------------------------------------
sampler TilesSampler = sampler_state 
{
    texture = <tilesTexture>;
    AddressU  = CLAMP;        
    AddressV  = CLAMP;
    AddressW  = CLAMP;
    MIPFILTER = LINEAR;
    MINFILTER = LINEAR;
    MAGFILTER = LINEAR;
};

sampler MapSampler = sampler_state 
{
    texture = <mapTexture>;
    AddressU  = CLAMP;        
    AddressV  = CLAMP;
    AddressW  = CLAMP;
    MIPFILTER = POINT;
    MINFILTER = POINT;
    MAGFILTER = POINT;
};

//-----------------------------------
float4 PS_Sample( vertexOutput IN): COLOR
{
  float4 mapEntry = tex2D( MapSampler, IN.texCoordDiffuse );
  mapEntry.w *= 255.0f;
  float2 partial = IN.texCoordDiffuse.xy/tileSize.zz;
  float2 whole;
  float2 fraction = modf(partial,whole);
  float2 diffuseTex;
  diffuseTex.x = mapEntry.w*tileSize.x;
  diffuseTex.x += fraction.x*(tileSize.x)+tileSize.w;
  diffuseTex.y = fraction.y*(tileSize.y);
  //diffuseTex.z = 0;
  //diffuseTex.w = 0;
  float2 duvdx = ddx(IN.texCoordDiffuse.xy*tileSize.xx);
  float2 duvdy = ddy(IN.texCoordDiffuse.xy*tileSize.xx);
  float4 result = tex2Dgrad( TilesSampler, diffuseTex,duvdx,duvdy );
  if(result.w <= 0.75f)
  	clip(-1);
  
  return result;
}

//-----------------------------------
technique q0_p0_main
{
    pass p0 
    {		
		VertexShader = compile vs_3_0 VS_TransformAndFrame();
		PixelShader  = compile ps_3_0 PS_Sample();
    }
}
